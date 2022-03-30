//
//  MemoryGame.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 26/01/2022.
//

import Foundation
import CoreVideo

struct MemoryGame<CardContent> where CardContent: Equatable {
    private(set) var GameIsWon = false
    private(set) var cards: Array<Card>
    private var indexOFFaceUpCard: Int? {
        get { cards.indices.filter({ cards[$0].isFaceUp }).oneAndOnly }
        set { cards.indices.forEach {cards[$0].isFaceUp = ($0 == newValue)} }
    }
    private(set) var theme: Theme
    var score = 0
    var SeenCard = Set<Int>()
    

    mutating func choose(_ card: Card) {
        if let chosenIndex = cards.firstIndex(where: {$0.id == card.id}),
            !cards[chosenIndex].isFaceUp,
            !cards[chosenIndex].isMatched
        {
            if let potentialIndex = indexOFFaceUpCard {
                if cards[chosenIndex].content == cards[potentialIndex].content {
                    cards[chosenIndex].isMatched = true
                    cards[potentialIndex].isMatched = true
                    score += 2
                    if (cards.indices.filter({cards[$0].isMatched}).count == cards.count) {
                        GameIsWon = true
                    }
                } else {
                    if (SeenCard.contains(cards[chosenIndex].id)) {
                        score -= 1
                    } else {
                        if (SeenCard.contains(cards[potentialIndex].id)) {
                            score -= 1
                        }
                    }
                    
                    SeenCard.insert(cards[chosenIndex].id)
                    SeenCard.insert(cards[potentialIndex].id)
                }
                cards[chosenIndex].isFaceUp = true
            } else {
                indexOFFaceUpCard = chosenIndex
            }
        }
    }
    
    func isWon() -> Bool {
        return GameIsWon
    }
    
    init(numberOfPairsOfCards : Int, theme: Theme, createCardContent: (Int) -> CardContent) {
        cards = []
        self.theme = theme
        for pairIndex in 0..<numberOfPairsOfCards {
            let content = createCardContent(pairIndex)
            cards.append(Card(content: content, id: pairIndex*2))
            cards.append(Card(content: content, id: pairIndex*2+1))
        }
        cards.shuffle()
      }
    
    struct Card: Identifiable {
        var isFaceUp = false
        var isMatched = false
        let content: CardContent
        let id: Int
    }
}

extension Array {
    var oneAndOnly: Element? {
        if self.count == 1 {
            return self.first
        } else {
            return nil
        }
    }
}
