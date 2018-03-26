let component = ReasonReact.statelessComponent("Page");

let handleClick = (_event, _self) => Js.log("clicked!");

let tape: Tape.tape = {
  previous: [Symbol.One],
  current: Symbol.One,
  next: [Symbol.Zero, Symbol.Zero, Symbol.One],
};

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