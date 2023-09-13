type onRowsRenderedParams = {
  startIndex: int,
  stopIndex: int,
  overscanStartIndex: int,
  overscanStopIndex: int,
};

[@mel.module "react-virtualized"] [@react.component]
external make:
  (
    ~autoHeight: bool=?,
    ~deferredMeasurementCache: 'deferredMeasurementCache=?,
    ~isScrolling: bool=?,
    ~width: int,
    ~height: int,
    ~overscanRowCount: int=?,
    ~rowCount: int,
    ~rowHeight: 'rowHeight,
    ~rowRenderer: 'rowRenderer=?,
    ~scrollToAlignment: string=?,
    ~scrollToIndex: 'scrollToIndex=?,
    ~scrollTop: int=?,
    ~className: string=?,
    ~onScroll: int => unit=?,
    ~onRowsRendered: onRowsRenderedParams => unit=?,
    ~ref: ReactDOM.domRef=?,
    unit
  ) =>
  React.element =
  "List";

let recomputeSize: Dom.element => unit = [%raw
  {|
  (virtualizedList) => {
    virtualizedList.recomputeGridSize();
  }
|}
];

let scrollToRow: (Dom.element, int) => unit = [%raw
  {|
  (virtualizedList, rowIndex) => {
    virtualizedList.scrollToRow(rowIndex);
  }
|}
];
