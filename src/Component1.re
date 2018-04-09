let component = ReasonReact.statelessComponent("Page");

let handleClick = (_event, _self) => Js.log("clicked!");

let tape: Tape.tape = {
  previous: [Symbol.One],
  current: Symbol.One,
  next: [Symbol.Zero, Symbol.Zero, Symbol.One],
};

let state3: State.state = {
  name: "state3",
  message: Some("custom-halt-message"),
  action: Halt,
};

let state2: State.state = {
  name: "state2",
  message: None,
  action:
    Rule(
      sym =>
        switch (sym) {
        | Symbol.Zero => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state3,
          }
        | Symbol.One => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state3,
          }
        | Symbol.Blank => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state3,
          }
        },
    ),
};

let state1: State.state = {
  name: "initial",
  message: None,
  action:
    Rule(
      sym =>
        switch (sym) {
        | Symbol.Zero => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state2,
          }
        | Symbol.One => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state2,
          }
        | Symbol.Blank => {
            write: Symbol.Blank,
            move: HeadMove.Right,
            next: state2,
          }
        },
    ),
};

let tm: TuringMachine.turingMachine = {
  state: state1,
  tape,
};

TuringMachine.run(tm);

let make = (~message, _children) => {
  ...component,
  render: self =>
    <div onClick=(self.handle(handleClick))>
      <pre>
        (
          ReasonReact.stringToElement(Tape.toString(tape))
        )
      </pre>
    </div>,
};