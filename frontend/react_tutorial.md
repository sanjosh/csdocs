
React Components = pure functions

ReactDOM.render(element, doc.getElementByID('root')

## React elements

DOM = set of React elements

JSX produces React.createElement

Unlike browser DOM elements, React elements are plain objects, and are cheap to create. React DOM takes care of updating the DOM to match the React elements.

You can build collections of elements and include them in JSX using curly braces {}.

## Keys

Keys help React identify which items have changed, are added, or are removed.  Keys should be given to the elements inside the array to give the elements a stable identity:
https://reactjs.org/docs/lists-and-keys.html


## Props and State

Props are immutable arguments

State is internal

1. do not modify state directly; call setState to change it
2. State updates are merged
3. state update is async
https://reactjs.org/docs/state-and-lifecycle.html

## sharing state

lift state to nearest parent

when the child component wants to update its "state", it calls this.props.onTemperatureChange:

https://reactjs.org/docs/lifting-state-up.html


## Mount 

mount/unmount = when component is rendered for first time

## controlled component

In HTML, form elements such as <input>, <textarea>, and <select> typically maintain their own state and update it based on user input. In React, mutable state is typically kept in the state property of components, and only updated with setState().

An input form element whose value is controlled by React in this way is called a “controlled component”.

## events

onClick

onChange

Event handlers are passed SyntheticEvents

https://reactjs.org/docs/events.html
