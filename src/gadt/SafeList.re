type empty =
  | Empty;
type nonEmpty =
  | NonEmpty;

type t('a, 's) =
  | []: t('a, empty)
  | ::(('a, t('a, 's))): t('a, nonEmpty);

let rec length: type s. t(_, s) => int =
  fun
  | [] => 0
  | [_, ...xs] => 1 + length(xs);

let head: type a. t(a, nonEmpty) => a =
  fun
  | [x, ..._] => x;

/* let rec tail: type a. t(a, nonEmpty) => a =
   fun
   | [x] => x
   | [_, ...xs] => tail(xs); */
