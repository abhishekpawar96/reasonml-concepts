// ADT
type rgb = Red | Green | Blue;

// Polymorphic ADT
type rgb' = [`Red | `Green | `Blue];

// Polymorphic constructors exist on their own
let makeIntBool: [> `Int((int, bool)) ] = `Int(123, true);

// all types that have at least the constructor `Red
type red = [ `Red ];
let red: [> `Red ] = `Red; 

// Extending polymorphic variants 
type green = [ `Green ];
type blue = [ `Blue ];
type rgb'' = [ red | green | blue ];
type color' = [`Red | `Orange | `Yellow | `Green | `Blue | `Purple];

// Type compatibility
type rg = [`Red | `Green];
let id: rgb' => rgb' = (x: rgb') => x;
let rg: rg = `Red
let rg': [> `Red | `Green]  = `Red
// id(rg);
id(rg');
type rgbw = [`Red | `Green | `Blue | `White ]
let rg'': rgbw  = `Red
// id(rg'');
let id' = (x: [> `Red | `Green | `Blue]) => x;
id'(rg'');
let id''' = (x: [> rgb']) => x;

// Lower bounds
let lower = (_x: [> `Red | `Green]) => true;
lower(`Red: [`Red | `Green | `Blue]);
// lower(`Red: [`Red]);

// Upper bounds 
let upper = (_x: [< `Red | `Green]) => true;
upper(`Red: [`Red | `Green]);
// upper(`Red: [`Red | `Green | `Blue]);
upper(`Red: [`Red]);

// contraints
type t('a) = [> `Red] as 'a;
// type t('a) = 'a constraint 'a = [> `Red ];

let even1: ([< `Data(int) ]) => bool = (x) =>
  switch x {
  | `Data(n) => (n mod 2) == 0
  };
let even2: ([< `Data(string) ]) => bool = (x) =>
  switch x {
  | `Data(s) => (String.length(s) mod 2) == 0
  };

let even = x => even1(x) && even2(x);
// let even: ([< `Data(string & int) ]) => bool
//`Data(string & int)

// Two constraints
let f: (([< `Green | `Red > `Red ] as 'a)) => 'a = 
    (x: [> `Red]): [< `Red | `Green] => x;

let f': (([> `Green | `Red ] as 'a)) => 'a  = 
    (x: [> `Red]): [> `Red | `Green] => x;

let f'': ([ `Green | `Red ]) => [ `Green | `Red ] = 
    (x: [>`Red]): [`Red | `Green] => x;

let f''': ([ `Red ]) => [ `Red ] = 
    (x: [`Red]): [< `Red | `Green] => x;

let f'''': ([ `Green | `Red ]) => [ `Green | `Red ] = 
    (x: [`Red | `Green]): [`Red | `Green] => x;

// Monomorphic type vs. constraint
let id1 = (x: rgb') => x;
// let id1: (rgb) => rgb = <fun>
let id2 = (x:[> rgb']) => x;
// let id2: (([> rgb ] as 'a)) => 'a = <fun>;
type c3 = [ `Blue | `Green | `Red ];
id1(`Red: c3);
id2(`Red: c3);