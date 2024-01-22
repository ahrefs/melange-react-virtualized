type props = {
  defaultHeight: int,
  fixedHeight: bool,
  fixedWidth: bool,
  minHeight: int,
};

type t = {rowHeight: int};

[@mel.module "react-virtualized"] [@mel.new] external make: props => t = "CellMeasurerCache";

let clear: (t, int) => unit = [%raw {|
  (cache, rowIndex) => {
    cache.clear(rowIndex);
  }
|}];

let clearAll: t => unit = [%raw {|
  (cache) => {
    cache.clearAll();
  }
|}];
