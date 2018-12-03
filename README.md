# bs-ws

Simple node websocket implementation for Reason

[![npm](https://img.shields.io/npm/v/bs-ws.svg)](https://www.npmjs.com/package/bs-ws)

[![GitHub issues](https://img.shields.io/github/issues/kfish610/bs-ws.svg)](https://github.com/kfish610/bs-ws/issues)


# Installation

```
npm install --save bs-ws
```
or
```
npm i -S bs-ws
```

Then add bs-ws to bs-dependencies in your bsconfig.json:
```
{
  ...
  "bs-dependencies": ["bs-ws"]
}
```

# Examples

Simple Example
```
let ws = WebSocket.make("wss://www.example.com");
WebSocket.(
ws
-> on(`message((data) => Js.log("Message: " ++ data)))
-> on(`close((code, reason) => Js.log("Closed: " ++ string_of_int(code) ++ reason)))
-> on(`open_(() => Js.log("Opened!")))
-> on(`error(error => Js.log("Error: " ++ ErrorEvent.message(error))))
);
```

Example with subprotocols
```
let ws = WebSocket.makeWithProtocols("wss://www.example.com", [| "soap" |]);
WebSocket.(
ws
-> on(`message((data) => Js.log("Message: " ++ data)))
-> on(`close((code, reason) => Js.log("Closed: " ++ string_of_int(code) ++ reason)))
-> on(`open_(() => Js.log("Opened!")))
-> on(`error(error => Js.log("Error: " ++ ErrorEvent.message(error))))
);
```

Send
```
let ws = WebSocket.make("wss://www.example.com");
WebSocket.(
ws
-> send("Hello World!")
);
```