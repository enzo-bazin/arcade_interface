# EventDispatcher — logique EDA en MVC

Ce document explique **comment fonctionne le `EventDispatcher`** dans une architecture **Event-Driven Architecture (EDA)** appliquée à un modèle **MVC** (Model / View / Controller), et **quelles fonctions doivent être codées**.

Objectif: découpler la production d’événements (input, gameplay, navigation…) de leur traitement métier.

---

## 1) Position du dispatcher dans MVC

- **Controller**: capte les entrées (clavier, système, etc.) et crée des événements (Event provient de la lib graphique par exemple avec SfKeyIsPressed puis return de l'évent normalisé).
- **Model (`IGameState`)**: contient l’état métier (positions, sélection, transitions, etc.).
- **View**: lit l’état et l’affiche.
- **EventDispatcher**: route les événements vers les bons listeners, sans connaître le détail métier.

Le dispatcher est donc un médiateur: il reçoit des `IArcadeEvent*`, identifie leur type runtime, puis notifie les listeners inscrits sur ce type.

---

## 2) Principes EDA utilisés

- **Publish / Subscribe**:
	- un listener s’inscrit (`subscribe`) sur un type d’événement,
	- quand un événement de ce type est publié (`publish`), tous les listeners associés sont appelés.
- **Routage par type**:
	- le dispatch s’appuie sur `typeid` et `std::type_index`,
	- un événement est dispatché selon son type concret.
    - Exemple : il est possible de créé une array avec en index des class avec typeid `listener[typeid ({la class})]
- **Normalisation**:
	- tous les événements partagent une base commune `IArcadeEvent`,
	- tous les listeners exposent un contrat uniforme `onEvent(...)`.

---

## 3) Structures internes (vue conceptuelle)

- **`listeners`**: map `TypeEvent -> liste de listeners`
	- contient les abonnements effectifs.
- **`dispatchTable`**: map `TypeEvent -> fonction de dispatch`
	- chaque entrée sait caster vers le bon type puis appeler `publish`.
- **`_dispatchLimit`**:
	- limite le nombre d’événements traités par tick/update (exemple 5).
- **`_gameState`**:
	- référence l’état de jeu courant, injecté par `setGameState`.

---

## 4) Cycle complet d’un événement

1. Le module de jeu enregistre les types qu’il veut surveiller via `registerEvent<T>()`.
2. Il abonne ses listeners via `subscribe<T>(...)` (donc chaque listener écoute un event).
3. Les événements entrants sont ajoutés dans une file (`pendingEvents`).
4. `dispatchEvents(...)` traite jusqu’à la limite:
	 - prend chaque event,
	 - trouve son dispatcher dans `dispatchTable`,
	 - exécute la fonction associée qui appelle `publish`.
5. `publish(...)`:
	 - retrouve la liste de listeners du type,
	 - parcourt la liste,
	 - appelle `onEvent(event)` pour chacun.
6. Les événements traités sont supprimés de la file.

---

## 5) Subscribe d’un listener (ce qu’il se passe)

Quand on subscribe un listener de type `EventType`:

- le listener concret est encapsulé dans un conteneur polymorphique (`IEventListenerContainer`),
- ce conteneur est ajouté à la liste `listeners[typeid(EventType)]`.

Pourquoi ce conteneur ?
- parce que les listeners sont template (`IEventListener<TEvent>`),
- et le dispatcher doit stocker des listeners hétérogènes dans une collection unique pour la gestion de mémoire et donc utiliser que des unique ptr (ce n'est pas obligatoire si vous faire un vector de void * en raw pointer)

---

## 6) Contrats à coder (prototypes uniquement)

### EventDispatcher

```cpp
void setGameState(IGameState *gameState);

template<typename EventType>
void subscribe(std::unique_ptr<IEventListener<EventType>> listener);

template<typename EventType>
void publish(EventType &event);

void dispatchEvents(std::vector<IArcadeEvent *> &events);

template<typename EventType>
void registerEvent();
```

### Base event

```cpp
virtual ~IArcadeEvent() = default;
```

### Listener typé

```cpp
template<typename TEvent>
virtual void onEvent(TEvent &event) = 0;
```

### Conteneur polymorphique de listener

```cpp
virtual ~IEventListenerContainer() = default;
virtual void onEvent(arc::IArcadeEvent &event) = 0;
```

---

## 7) Règles de normalisation

- **Événements**:
	- suffixe `Event` (ex: `InputEnterKeyPressedEvent`),
	- héritent tous de `IArcadeEvent`,
	- représentent un fait passé (pas une commande).
- **Listeners**:
	- suffixe `EventListener`,
	- un listener = une responsabilité claire.
- **Enregistrement**:
	- tout type publié doit être `registerEvent<T>()` avant dispatch.

---

## 8) Points d’attention importants

- `dispatchEvents` traite un nombre borné d’événements par frame: utile pour la stabilité, mais implique qu’une file peut conserver des events pour la frame suivante.
- les événements traités sont détruits ensuite: la propriété mémoire de la file doit être claire et unique.
- si un type n’est pas enregistré dans `dispatchTable`, il ne sera pas dispatché.
- si aucun listener n’est abonné à un type, `publish` n’a aucun effet (comportement attendu).

---

## 9) Résumé opérationnel

Pour intégrer un nouvel événement:

1. créer la classe d’événement (hérite de `IArcadeEvent`),
2. créer son listener (`IEventListener<TEvent>`),
3. appeler `registerEvent<TEvent>()`,
4. appeler `subscribe<TEvent>(...)`,
5. pousser l’event dans la file puis laisser `dispatchEvents(...)` faire le routage.

Avec ce flux, le moteur reste découplé, extensible et cohérent avec une architecture EDA en MVC.
