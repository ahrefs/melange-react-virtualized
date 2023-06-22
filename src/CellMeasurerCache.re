type props = {
  defaultHeight: int,
  fixedHeight: bool,
  fixedWidth: bool,
  minHeight: int,
};

type t = {rowHeight: int};

[@bs.module "react-virtualized"] [@bs.new] external make: props => t = "CellMeasurerCache";

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
