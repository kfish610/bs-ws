let ws = WebSocket.makeWithProtocols("wss://www.example.com", [| "soap" |]);
WebSocket.(
ws
|. on(`message((data) => Js.log("Message: " ++ data)))
|. on(`close((code, reason) => Js.log("Closed: " ++ string_of_int(code) ++ reason)))
|. on(`open_(() => Js.log("Opened!")))
|. on(`error(error => Js.log("Error: " ++ ErrorEvent.message(error))))
);