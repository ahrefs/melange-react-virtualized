module RV = ReactVirtualized;

[@react.component]
let make =
    (
      ~items: array('a),
      ~selectedIndex=?,
      ~getKey: 'a => string,
      ~defaultRowHeight=53,
    ) => {
  let itemsCount = items->Array.length;

  /* Store cellMeasurer in state, otherwise scroll is laggy */
  let (cellMeasurer, _) =
    React.useState(() =>
      RV.CellMeasurerCache.make({
        defaultHeight: defaultRowHeight,
        fixedHeight: false,
        fixedWidth: true,
        minHeight: defaultRowHeight,
      })
    );

  React.useEffect1(
    () => {
      RV.CellMeasurerCache.clearAll(cellMeasurer);
      None;
    },
    [|items|],
  );

  let rowRenderer = data => {
    let index = data##index;
    <RV.CellMeasurer
      cache=cellMeasurer
      columnIndex=0
      key={getKey(items[index])}
      parent={data##parent}
      rowIndex=index>
      <div />
    </RV.CellMeasurer>;
  };

  <RV.AutoSizer>
    {({height, width}) =>
       <RV.VirtualizedList
         autoHeight=false
         height
         width
         overscanRowCount=100
         scrollToIndex=selectedIndex
         rowCount=itemsCount
         rowHeight={cellMeasurer.rowHeight}
         rowRenderer
       />}
  </RV.AutoSizer>;
};
