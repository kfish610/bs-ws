let ws = Ws.WebSocket.make("wss://www.example.com");
Ws.WebSocket.(
ws
-> send("Hello World!")
);