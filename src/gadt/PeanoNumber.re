type zero =
  | Zero;

type succ('a) =
  | Succ('a);

type nat(_) =
  | Zero: nat(zero)
  | Succ(nat('a)): nat(succ('a));

let rec inc: nat('a) => nat(succ('a)) =
  fun
  | n => Succ(n);

let rec dec: nat(succ('a)) => nat('a) =
  fun
  | Succ(a) => a;

let rec isEqual: type a b. (nat(a), nat(b)) => bool =
  (i, j) =>
    switch (i, j) {
    | (Zero, Zero) => true
    | (Succ(n), Succ(m)) => isEqual(n, m)
    | (_, _) => false
    };

let rec eval: type a. nat(a) => int =
  fun
  | Zero => 0
  | Succ(n) => 1 + eval(n);

type one_ = nat(succ(zero));
let one: one_ = Succ(Zero);

type two_ = nat(succ(succ(zero)));
let two: two_ = Succ(Succ(Zero));

type three_ = nat(succ(succ(succ(zero))));
let three: three_ = Succ(two);
