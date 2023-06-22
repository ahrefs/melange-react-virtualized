[@bs.module "react-virtualized"] [@react.component]
external make:
  (
    ~label: string=?,
    ~cellDataGetter: 'cellDataGetter=?,
    ~dataKey: string=?,
    ~disableSort: bool=?,
    ~flexGrow: int=?,
    ~flexShrink: int=?,
    ~width: int=?,
    ~height: int=?,
    ~minWidth: int=?,
    ~maxWidth: int=?,
    ~headerRenderer: 'headerRenderer=?,
    ~cellRenderer: 'cellRenderer=?,
    unit
  ) =>
  _ =
  "Column";
