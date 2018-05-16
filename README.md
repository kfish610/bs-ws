# bs-ws

Simple node websocket implementation for Reason

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
|. on(`message((data) => Js.log("Message: " ++ data)))
|. on(`close((code, reason) => Js.log("Closed: " ++ string_of_int(code) ++ reason)))
|. on(`open_(() => Js.log("Opened!")))
);
```

Example with subprotocols
```
let ws = WebSocket.makeWithProtocols("wss://gateway.discord.gg/?v=6&encoding=json", [| "soap" |]);
WebSocket.(
ws
|. on(`message((data) => Js.log("Message: " ++ data)))
|. on(`close((code, reason) => Js.log("Closed: " ++ string_of_int(code) ++ reason)))
|. on(`open_(() => Js.log("Opened!")))
);
```

Send
```
let ws = WebSocket.make("wss://www.example.com");
WebSocket.(
ws
|. send("Hello World!")
);
```