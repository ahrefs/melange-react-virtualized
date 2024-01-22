[@mel.module "react-virtualized"] [@react.component]
external make:
  (~cache: 'cache, ~columnIndex: int, ~parent: 'parent, ~rowIndex: int, ~children: 'children) => React.element =
  "CellMeasurer";
