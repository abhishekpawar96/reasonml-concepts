(* - default/optional parameters
- ref
- switch with when
- objects 
- open and closed object 
- Js.Dict
- copy object with ...
- Js.Nullable
- ->
- @bs.obj
- @bs.abstract
- @bs.accessor
- Variant
- Polymorphic Variant
- Phantom Types
- GADTs *)

(* - JS Objects
	- 1. Js.Dict.t
	- 2. Records -> ReaonML Records -> Js.Objects (@bs abstract | @bs obj)
	- 3. Js.t() for ReasonML Objects -> JS Objects
 *)

(* ==: physical equal, compares data structures deeply: (1, 2) == (1, 2) is true. Convenient, but use with caution
Compare 2 values deeply, so incur accidental performance cost if not used carefully.
Don't actually work intuitively in many cases, e.g. 2 floating numbers that look the same but have miniscule precision difference 
will look different for the physical equal, and 2 sets that have the same items might be physically different because of the items' order difference in the implementation
===: referential equal, compares shallowly. (1, 2) === (1, 2) is false. let myTuple = (1, 2); myTuple === myTuple is true.
 *)

(* tuple compile to JavaScript arrays *)

(* Records are like JavaScript objects but are 
- lighter
- immutable by default
- fixed in field names and types
- very fast
- a bit more rigidly typed
- compiles to a JavaScript object still

Record Types Are Found By Field Name
Note that there's no punning for a single record field! {foo} doesn't do what you expect (it's a block that returns the value foo).
Because record compiles to a straightforward JS object, you can directly model incoming JS objects as Reason records, no conversion functions needed
 *)

type account =
  | Facebook(string, int) (* /* 2 arguments */ *);
type account2 =
  | Instagram((string, int)) (* /* 1 argument - happens to be a 2-tuple */ *);

type foo = Int(int) | String(string)

(* Variants are the same: a function can't accept an arbitrary constructor shared by two different variants. Again, such feature exists, it's called a polymorphic variant *)

(* null or undefined *)

(* Never, EVER, pass a nested option value (e.g. Some(Some(Some(5)))) into the JS side. *)

(* Never, EVER, annotate a value coming from JS as option('a). Always give the concrete, non-polymorphic type. *)

let result = name->preprocess->Some

type coordinates('a) = ('a, 'a, 'a);

let optionBoolToBool = opt =>
  switch (opt) {
  | Some(trueOrFalse) => trueOrFalse
  | None => false
  };

type tesla = {
  .
  color: string,
};

let obj: tesla = {
  val red = "Red";
  pub color = red;
};

Js.log(obj#color)

(* https://reasonml.chat/t/bs-deriving-abstract-vs-bs-obj-external/1187/2 *)