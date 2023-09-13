type indexData = {index: int};

[@mel.module "react-virtualized"] [@react.component]
external make:
  (
    ~autoHeight: bool=?,
    ~deferredMeasurementCache: 'deferredMeasurementCache=?,
    ~disableHeader: bool=?,
    ~headerClassName: string=?,
    ~headerHeight: int,
    ~headerRowRenderer: 'headerRowRenderer=?,
    ~isScrolling: bool=?,
    ~itemCount: int=?,
    ~itemSize: int=?,
    ~itemData: 'itemData => unit=?,
    ~width: int,
    ~height: int,
    ~overscanRowCount: int=?,
    ~rowCount: int,
    ~rowHeight: 'rowHeight,
    ~rowGetter: Js.t({..}) => 'rowGetter,
    ~rowRenderer: 'rowRenderer=?,
    ~rowStyle: Js.t({..}) => 'rowStyle=?,
    ~scrollToIndex: 'scrollToIndex=?,
    ~scrollTop: int=?,
    ~className: string=?,
    ~rowClassName: Js.t({..}) => string,
    ~onScroll: int => unit=?,
    ~onRowClick: 'onRowClick=?,
    ~children: 'a,
    unit
  ) =>
  React.element =
  "Table";
