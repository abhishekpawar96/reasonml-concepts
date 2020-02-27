Js.log("Hello, BuckleScript and Reason!");


Js.log("\n GADTs Usage");

Js.log("1. EVAL");

Primitive.eval(Int(64)) -> Js.log;
Primitive.eval(String("hellpo")) -> Js.log;
Primitive.eval(Float(43.0234234)) -> Js.log;
Primitive.eval(Bool(false)) -> Js.log;


Js.log("1. HLIST");

HList.List'.[1, 2, 3, 4]-> Js.log;

HList.List.["1", 1, false, 4.645]-> Js.log;

HList.List.["1", 1, false, 4.645]-> HList.List.length->Js.log;