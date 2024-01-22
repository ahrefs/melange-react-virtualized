type children = {
  width: int,
  height: int,
};

[@mel.module "react-virtualized"] [@react.component]
external make:
  (
    ~disableHeight: bool=?,
    ~onScroll: int => unit=?,
    ~onResize: unit => unit=?,
    ~children: children => React.element
  ) =>
  React.element =
  "AutoSizer";
