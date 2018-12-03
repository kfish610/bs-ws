let ws = WebSocket.make("wss://www.example.com");
WebSocket.(
ws
-> send("Hello World!")
);