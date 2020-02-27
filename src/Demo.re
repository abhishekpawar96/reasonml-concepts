Js.log("Hello, BuckleScript and Reason!");

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
/* SafeList.[] -> SafeList.head -> Js.log; */

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