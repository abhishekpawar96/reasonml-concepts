open PeanoNumber;

type t('a, _) =
  | []: t('a, nat(zero))
  | ::('a, t('a, nat('l))): t('a, nat(succ('l)));

/*
 - In a similar manner as the SafeList, here we provide an extra type parameter to our list type and use it store the size of the list.
 - For an `empty` list the size is zero, and for the `cons`, the size is `succ` of the existing list.
 - In the `pop` function, we specify in the type signature that input will have at-least one element by saying input type to be `nat(succ(a))` and the return will have a size smaller thus having type `nat(a)`
 - Same goes for `push`, we don't have any constraints on length for input type by specifying `nat(a)` but in the return type length has a type `nat(succ(a))`
 - The implementation of `push` provides type safe guarantee that the list of length will match the one encoded in type and same goes for `pop`, `pop` won't compile on empty lists.
 */

let rec length: type a. t(_, a) => int =
  fun
  | [] => 0
  | [_, ...xs] => 1 + length(xs);

let pop: type a. t(_, nat(succ(a))) => t(_, nat(a)) =
  fun
  | [_, ...xs] => xs;

let push: type a. (t(_, nat(a)), _) => t(_, nat(succ(a))) =
  (l, v) =>
    switch (l) {
    | [] => [v]
    | xs => [v, ...xs]
    };
