export class WebSocketService {
    constructor() {
        this.socket = null;
        this.playerNumber = 0;
    }
    static getInstance() {
        if (!WebSocketService.instance) {
            WebSocketService.instance = new WebSocketService();
        }
        return WebSocketService.instance;
    }
    getSocket() {
        return this.socket;
    }
    getPlayerNumber() {
        return this.playerNumber;
    }
    setPlayerNumber(playerNumber) {
        this.playerNumber = playerNumber;
    }
    connect(gameId) {
        // Close existing socket if it exists
        if (this.socket && this.socket.readyState === WebSocket.OPEN) {
            console.log('Reusing existing WebSocket connection');
            return this.socket;
        }
        console.log(`Creating new WebSocket connection for game: ${gameId}`);
        this.socket = new WebSocket(`ws://localhost:3000/game/${gameId}`);
        return this.socket;
    }
    close() {
        if (this.socket && this.socket.readyState === WebSocket.OPEN) {
            this.socket.close(1000, "Application closing");
            this.socket = null;
        }
    }
}
