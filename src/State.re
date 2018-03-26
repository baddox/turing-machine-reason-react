type state = {
  name: string,
  message: option(string),
  action,
}
and action =
  | Rule(Symbol.symbol => transition)
  | Halt
and transition = {
  write: Symbol.symbol,
  move: HeadMove.headMove,
  next: state,
};

let toSentence = state => "todo";