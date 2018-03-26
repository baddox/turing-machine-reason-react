type tape = {
  /* previous is in reverse order, i.e.
     List.nth(previous, 0) is directly to the left of
     current.
        */
  previous: list(Symbol.symbol),
  current: Symbol.symbol,
  next: list(Symbol.symbol),
};

let write = (symbol, tape) => {...tape, current: symbol};

let move = (move, tape) =>
  switch (move) {
  | HeadMove.Left => {
      previous:
        switch (tape.previous) {
        | [] => []
        | [_head, ...rest] => rest
        },
      current:
        switch (tape.previous) {
        | [] => Symbol.Blank
        | [head, ..._rest] => head
        },
      next: [tape.current] @ tape.next,
    }
  | HeadMove.Right => {
      previous: tape.previous @ [tape.current],
      current:
        switch (tape.next) {
        | [] => Symbol.Blank
        | [head, ..._rest] => head
        },
      next:
        switch (tape.next) {
        | [] => []
        | [_head, ...rest] => rest
        },
    }
  | HeadMove.Stay => tape
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