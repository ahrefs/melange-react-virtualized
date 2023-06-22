# melange-react-virtualized

These are the [Melange](https://melange.re/) bindings for [react-virtualized](https://github.com/bvaughn/react-virtualized).
🚧 It is not completed, we are adding bindings as we go. Doesn't follow semver at this point. 🚧

# Install

Install [opam](https://opam.ocaml.org/) package manager.

Then:

```
opam pin add melange-react-virtualized.dev git+https://github.com/ahrefs/melange-react-virtualized.git#master
```

The bindings support the version `^9.0.2` of `react-virtualized` npm package, which should be installed separately:

```json
  "dependencies": {
    "react-virtualized": "^9.0.2"
  }
```

# Setup

Add `melange-react-virtualized` to the `libraries` in your `dune` file:

```dune
; ...
  (libraries melange-react-virtualized)
; ...
```

to include styles

```js
[%bs.raw {|require("react-virtualized/styles.css")|}];
```

# Usage Example

See [this test file](./tests/test.re).

Check [react-virtualized documentation](https://github.com/bvaughn/react-virtualized/tree/master/docs#documentation) for available props.
