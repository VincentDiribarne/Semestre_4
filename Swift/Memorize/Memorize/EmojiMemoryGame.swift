//
//  EmojiMemoryGame.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 26/01/2022.
//

import SwiftUI

class EmojiMemoryGame: ObservableObject {
    typealias Card = MemoryGame<String>.Card
    static var theme = ThemeManager.ChooseTheme()
    
    static func createMemoryGame() -> MemoryGame<String> {
        EmojiMemoryGame.theme = ThemeManager.ChooseTheme()
        return MemoryGame<String>(numberOfPairsOfCards: 15, theme: theme) { pairIndex in theme.listeEmoji[pairIndex]}
    }
    
    @Published private var model = createMemoryGame()
        
    var cards: Array<Card> {
        return model.cards
    }
    
    //Mark: - Intent(s)
    
    func choose(_ card: Card) {
        model.choose(card)
    }
    
    func newGame() {
        model = EmojiMemoryGame.createMemoryGame()
    }
    
    func isWon() -> Bool {
        model.isWon()
    }
    
    var color : Color {
        return model.theme.color
    }
    
    var score : Int {
        return model.score
    }
}
