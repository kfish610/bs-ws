type t;

type event = [
  | `close((int, string) => unit) 
  | `message(string => unit)
  | `open_(unit => unit)
  | `ping(Node.Buffer.t => unit)
  | `pong(Node.Buffer.t => unit)
  | `error(Dom.errorEvent => unit)
];

type readyStateType = 
  | CONNECTING
  | OPEN
  | CLOSING
  | CLOSED;

let string_of_readyState = (readyState) =>
  switch(readyState) {
  | CONNECTING => "CONNECTING"
  | OPEN => "OPEN"
  | CLOSING => "CLOSING"
  | CLOSED => "CLOSED"
  };

[@bs.new] [@bs.module] external make: string => t = "isomorphic-ws";
[@bs.new] [@bs.module] external makeWithProtocols: (string, array(string)) => t = "isomorphic-ws";
[@bs.get] external getReadyState: t => readyStateType = "readyState";

[@bs.send] external on: (t, [@bs.string] [
    | `close((int, string) => unit) 
    | `message(string => unit)
    | [@bs.as "open"] `open_(unit => unit)
    | `ping(Node.Buffer.t => unit)
    | `pong(Node.Buffer.t => unit)
    | `error(Dom.errorEvent => unit)
]) => t = "on";

[@bs.send] external send: (t, string) => unit = "send";