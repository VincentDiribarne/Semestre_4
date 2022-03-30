//
//  ScoreBoardEndingView.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 24/03/2022.
//

import SwiftUI

struct ScoreBoardEndingView : View {
    @Binding var endOfGame : Bool
    @ObservedObject var game: EmojiMemoryGame
    
    var body: some View {
        Text("Bien joué 🔥🔥")
            .font(.largeTitle)
        Text("")
        Text("Vous avez gagné avec un score de \(game.score) !")
            .font(.title3)
            .foregroundColor(game.color)
            .multilineTextAlignment(.center)
    }
}
