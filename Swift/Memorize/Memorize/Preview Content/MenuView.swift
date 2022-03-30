//
//  MenuView.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 24/03/2022.
//

import SwiftUI

struct MenuView: View {
    let game = EmojiMemoryGame()
    var body: some View {
            NavigationView {
                VStack(spacing: 30) {
                    Text("Choisissez votre mode").font(.title3).padding(.vertical, 10.0)
                    Spacer()
                    NavigationLink(destination: EmojiMemoryGameView(game: game)) {
                        Text("Jouer !")
                            .padding(.bottom, 40.0)
                    } .simultaneousGesture(TapGesture().onEnded{
                        game.newGame()
                    })

                    NavigationLink(destination: ScoreView()) {
                        Text("Score")
                            .padding(.bottom, 100.0)
                    }
                    Spacer()
                }
                .navigationTitle("")
            }
            .font(.largeTitle)
            .multilineTextAlignment(.center)
        }
}

struct MenuView_Previews: PreviewProvider {
    static var previews: some View {
        MenuView()
    }
}
