// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$String = require("bs-platform/lib/js/string.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Symbol$ReactTemplate = require("./Symbol.bs.js");

function write(symbol, tape) {
  return /* record */[
          /* previous */tape[/* previous */0],
          /* current */symbol,
          /* next */tape[/* next */2]
        ];
}

function move(move$1, tape) {
  switch (move$1) {
    case 0 : 
        var match = tape[/* previous */0];
        var match$1 = tape[/* previous */0];
        return /* record */[
                /* previous */match ? match[1] : /* [] */0,
                /* current */match$1 ? match$1[0] : /* Blank */2,
                /* next */Pervasives.$at(/* :: */[
                      tape[/* current */1],
                      /* [] */0
                    ], tape[/* next */2])
              ];
    case 1 : 
        var match$2 = tape[/* next */2];
        var match$3 = tape[/* next */2];
        return /* record */[
                /* previous */Pervasives.$at(tape[/* previous */0], /* :: */[
                      tape[/* current */1],
                      /* [] */0
                    ]),
                /* current */match$2 ? match$2[0] : /* Blank */2,
                /* next */match$3 ? match$3[1] : /* [] */0
              ];
    case 2 : 
        return tape;
    
  }
}

function getSymbols(tape) {
  return List.concat(/* :: */[
              tape[/* previous */0],
              /* :: */[
                /* :: */[
                  tape[/* current */1],
                  /* [] */0
                ],
                /* :: */[
                  tape[/* next */2],
                  /* [] */0
                ]
              ]
            ]);
}

function toString(tape) {
  var previous = $$String.concat("", List.map(Symbol$ReactTemplate.toString, tape[/* previous */0]));
  var next = $$String.concat("", List.map(Symbol$ReactTemplate.toString, tape[/* next */2]));
  var current = ">" + (Symbol$ReactTemplate.toString(tape[/* current */1]) + "<");
  return previous + (current + next);
}

exports.write = write;
exports.move = move;
exports.getSymbols = getSymbols;
exports.toString = toString;
/* No side effect */
