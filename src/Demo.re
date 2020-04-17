Js.log("Hello, BuckleScript and Reason!");


// ==============================records and objects

Js.log("Records and Objects");

type person = {age: int, name: string};
type monster = {age: int, hasTentacles: bool};

let obj = {
  val red = "Red";
  pub color = red;
};

let obj2 = {
  val blue = "Blue";
  pub color = blue;
};

let getAge = (entity:person) => entity.age;

let getObj = (entity) => entity#color;

Js.log(getObj(obj));

let me = {
  age: 5,
  name: "Big Reason"
};

// (Js.log(getAge(me))

//==============================Js.t


type person1 = Js.t({
  .
  name: string,
});

type equalPerson = {. "name": string};

let personObj : person1 = {
  "name" : "blue"
};

Js.log(personObj##name);

// //==============================hashmap

let myPerson = Js.Dict.empty();
Js.Dict.set(myPerson, "name", "BLUE")
Js.log(myPerson);

// //==============================bindings

[@bs.obj] external makeProps: (~foo: string, ~bar: int=?, unit) => _ = "";

let make = makeProps(~foo="Test", ~bar=1, ());

[@bs.deriving abstract]
type props = {
  foo: string,
  [@bs.optional] bar: int
};

// bs.deriving abstract gives you a creation function
let make = props(~foo="Test", ~bar=1, ());


//==============================exceptions


exception MyException(string);

let unsafeMethod = () => raise(MyException("some message"));

switch ([||][0]) {
| exception(e) => Js.log((e)); 
| s => Js.log(s);
};

switch (unsafeMethod()) {
| exception(e) => Js.log((e)); 
| s => Js.log2( "safe: ", s);
};

try (
  Js.Exn.raiseError("oops!")
) {
| Js.Exn.Error(e) =>
  switch (Js.Exn.message(e)) {
  | Some(message) => Js.log({j|Error: $message|j})
  | None => Js.log("An unknown error occurred")
  }
};

//==============================gadts


Js.log("\n GADTs Usage");

Js.log("1. EVAL");

Primitive.eval(Int(64))->Js.log;
Primitive.eval(String("hellpo"))->Js.log;
Primitive.eval(Float(43.0234234))->Js.log;
Primitive.eval(Bool(false))->Js.log;

Js.log("2. HLIST");

HList.List'.[1, 2, 3, 4]->Js.log;

HList.List.["1", 1, false, 4.645, Some([1, 2, 4])]->Js.log;

HList.List.["1", 1, false, 4.645, Some([1, 2, 4])]
->HList.List.length
->Js.log;

Js.log("3. SAFELIST");

SafeList.[1, 2, 3]->SafeList.length->Js.log;
SafeList.[1, 2, 3]->SafeList.head->Js.log;
//  SafeList.[] -> SafeList.head -> Js.log;

Js.log("4. LENGTHLIST");

LengthList.[1, 2]->Js.log;
LengthList.[1, 2]->LengthList.push(3)->Js.log;
LengthList.[1, 2]
->LengthList.push(3)
->LengthList.pop
->LengthList.pop
->Js.log;
/* LengthList.[1]
->LengthList.pop
->LengthList.pop
->Js.log; */

