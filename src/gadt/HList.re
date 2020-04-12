module List' = {
  type t('a) =
    | []
    | ::(('a, t('a)));
};

module List = {
  type t =
    | []: t
    | ::(('a, t)): t;     
    // existential type

  let rec length: t => int =
    fun
    | [] => 0
    | [_, ...xs] => 1 + length(xs);
};

/*
   - The type of `[]` is pretty straight forward,
   but in the type of `::` we hide the extra parameter `'a`, by specifying the type of `::` as simply `t`.

   - Here type `'a` acts as an existential type.

   Existential types—unfortunately nothing to do with works of sartre—are a way of "squashing" a group of types into one, single type.
   Notice that the type signature just reads `poly` since we lost all the type information.
   This makes them quite limited, one won't even be able to write a `head` function for this implementation.

   https://drup.github.io/2016/08/02/difflists/ */
