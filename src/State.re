type state = {
  name: string,
  action: (Symbol.symbol) => action,
  halt: bool,
  message: option(string)
}
and action = {
  write: Symbol.symbol,
  move: HeadMove.headMove,
  next: state
};

