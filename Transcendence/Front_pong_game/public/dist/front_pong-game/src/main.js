var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
import { SettingsPage } from './pages/settingsPage.js';
import { Game } from './pages/gamePage.js';
import { WebSocketService } from './services/webSocketService.js';
class App {
    constructor() {
        this.DEFAULT_ROUTE = '#settings';
        this.GAME_ROUTE = '#game';
        this.MAX_ID_ATTEMPTS = 10;
        this.currentSettingsPage = null;
        this.currentGamePage = null;
        this.webSocketService = WebSocketService.getInstance();
        this.hashChangeListener = this.setupRouting.bind(this);
        window.addEventListener('hashchange', this.hashChangeListener);
        this.setupRouting().catch(error => {
            console.error('Failed to setup routing:', error);
            window.location.hash = this.DEFAULT_ROUTE;
        });
    }
    setupRouting() {
        return __awaiter(this, void 0, void 0, function* () {
            const path = window.location.hash || this.DEFAULT_ROUTE;
            const [page, gameId] = path.split('/');
            const settingsPage = document.getElementById('settings-page');
            const gamePage = document.getElementById('gameCanvas');
            const gameContainer = document.getElementById('game-container');
            if (!settingsPage || !gamePage || !gameContainer) {
                console.error('Required elements are not available in the DOM!');
                return; // Prevent errors if elements are not found
            }
            if (this.currentSettingsPage) {
                this.currentSettingsPage.cleanup();
                this.currentSettingsPage = null;
            }
            if (this.currentGamePage) {
                this.currentGamePage.stopGame();
                this.currentGamePage = null;
            }
            if (page === this.GAME_ROUTE) {
                try {
                    // Generate random gameId if none provided
                    const activeGameId = gameId || (yield this.generateGameId());
                    // Update URL with gameId
                    if (!gameId) {
                        window.location.hash = `#game/${activeGameId}`;
                        return; // Wait for hash change event to re-run setupRouting
                    }
                    this.currentGamePage = new Game(activeGameId);
                    settingsPage.style.display = 'none'; // Hide settings page
                    gameContainer.style.display = 'block'; // Show game container
                    gamePage.style.display = 'block'; // Show game page
                }
                catch (error) {
                    console.error('Failed to generate unique gameId:', error);
                    // Handle error (maybe redirect to error page or settings)
                    window.location.hash = this.DEFAULT_ROUTE;
                }
            }
            else {
                this.currentSettingsPage = new SettingsPage(); // store reference to settings page
                settingsPage.style.display = 'block'; // Show settings page
                gamePage.style.display = 'none'; // Hide game page
                gameContainer.style.display = 'none'; // Hide game container
            }
            window.addEventListener('hashchange', () => {
                this.setupRouting();
            });
        });
    }
    // Generate a random gameId that doesn't already exist
    generateGameId() {
        return __awaiter(this, void 0, void 0, function* () {
            let attempts = 0;
            while (attempts < this.MAX_ID_ATTEMPTS) {
                const gameId = Math.random().toString(36).substring(2, 8);
                try {
                    // Check if game exists by trying to fetch its status
                    const response = yield fetch(`http://localhost:3000/game/status/${gameId}`);
                    if (response.status === 404) {
                        // Game doesn't exist, we can use this ID
                        return gameId;
                    }
                }
                catch (error) {
                    console.error('Error checking gameId:', error);
                }
                attempts++;
            }
            throw new Error('Could not generate unique gameId after maximum attempts');
        });
    }
    cleanup() {
        window.removeEventListener('hashchange', this.hashChangeListener);
        if (this.currentSettingsPage) {
            this.currentSettingsPage.cleanup();
            this.currentSettingsPage = null;
        }
        if (this.currentGamePage) {
            this.currentGamePage.stopGame();
            this.currentGamePage = null;
        }
        this.webSocketService.close();
    }
}
// Initialize SPA
const app = new App();
window.addEventListener('beforeunload', () => {
    app.cleanup();
});
window.addEventListener('error', (event) => {
    console.error('Unhandled error:', event.error);
});
