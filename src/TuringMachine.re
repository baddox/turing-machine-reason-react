type turingMachine = {
  state: State.state,
  tape: Tape.tape,
};

let next = (tm: turingMachine) : turingMachine =>
  switch (tm.state.action) {
  | State.Rule(rule) =>
    let {write, move, next}: State.transition =
      rule(tm.tape.current);
    let tape =
      tm.tape |> Tape.write(write) |> Tape.move(move);
    {state: next, tape};
  | State.Halt => tm
  };

let toSentence = tm =>
  switch (tm.state.action) {
  | State.Rule(rule) =>
    let {write, move, next}: State.transition =
      rule(tm.tape.current);
    let statePhrase =
      if (next == tm.state) {
        "and remain in State:" ++ next.name;
      } else {
        "and switch to State:" ++ next.name;
      };
    String.concat(
      ", ",
      [
        "State:"
        ++ tm.state.name
        ++ " will "
        ++ Symbol.verbPhrase(write),
        HeadMove.verbPhrase(move),
        statePhrase,
      ],
    )
    ++ ".";
  | State.Halt =>
    "State:"
    ++ tm.state.name
    ++ (
      switch (tm.state.message) {
      | Some(message) =>
        " halted with this message: " ++ message
      | None => "halted with no message"
      }
    )
    ++ "."
  };

let toString = tm => {
  let lines = [Tape.toString(tm.tape), toSentence(tm)];
  String.concat("\n", lines);
};

let rec run = (tm: turingMachine) => {
  Js.log(toString(tm));
  switch (tm.state.action) {
  | State.Rule(_) =>
    let nextTm = next(tm);
    run(nextTm);
  | State.Halt => Js.log("halted in run")
  };
};