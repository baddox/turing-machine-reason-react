type symbol =
  | Zero
  | One
  | Blank;

let toChar = symbol =>
  switch (symbol) {
  | Zero => '0'
  | One => '1'
  | Blank => ' '
  };

let toString = symbol => String.make(1, toChar(symbol));