type headMove =
  | Left
  | Right
  | Stay;

let verbPhrase = headMove =>
  switch (headMove) {
  | Left => "move left"
  | Right => "move right"
  | Stay => "not move"
  };