type tape = {
  previous: list(Symbol.symbol),
  current: Symbol.symbol,
  next: list(Symbol.symbol),
};

let getSymbols = tape =>
  List.concat([
    tape.previous,
    [tape.current],
    tape.next,
  ]);

let toString = (tape: tape) : string => {
  let previous =
    tape.previous
    |> List.map(Symbol.toString)
    |> String.concat("");
  let next =
    tape.next
    |> List.map(Symbol.toString)
    |> String.concat("");
  let current =
    ">" ++ Symbol.toString(tape.current) ++ "<";
  previous ++ current ++ next;
};