//
//  ContentView.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 20/01/2022.


import SwiftUI

struct EmojiMemoryGameView: View {
    @State var endOfGame = false
    @ObservedObject var game: EmojiMemoryGame
    
    var body: some View {
        
        AspectVGrid(items: game.cards, aspectRatio: 2/3) { card in
            if card.isMatched && !card.isFaceUp {
                Rectangle().opacity(0)
            } else {
                CardView(card: card)
                    .padding(4)
                    .onTapGesture {
                        game.choose(card)
                        if game.isWon() {
                            endOfGame = true
                        }
                    }
            }
        }
        .foregroundColor(game.color)
        .padding(.horizontal)
        .popover(isPresented: $endOfGame) {
            ScoreBoardEndingView(endOfGame: $endOfGame, game: game).onDisappear(perform: game.newGame)
        }
        HStack {
            Spacer()
            Text("Score \(game.score)")
            Spacer()
            newGame
            Spacer()
        }
        .font(.title3)
        .foregroundColor(game.color)
        .padding(.bottom, 10.0)
    }
    
    
    var newGame : some View {
        Button(action: {
            game.newGame()
        }, label: {
            Text("New Game +")
        })
    }
}




struct CardView: View {
    let card: EmojiMemoryGame.Card
    
    var body: some View {
        GeometryReader { geometry in
            ZStack {
                let shape = RoundedRectangle(cornerRadius: DrawingConstant.cornerRadius)
                if card.isFaceUp {
                    shape.fill().foregroundColor(.white)
                    shape.stroke(lineWidth: DrawingConstant.lineWidth)
                    Text(card.content)
                        .font(font(in: geometry.size))
                } else if card.isMatched {
                    shape.opacity(0)
                } else {
                    shape.fill()
                }
            }
        }
    }
    
    private func font(in size: CGSize) -> Font {
        Font.system(size: min(size.width, size.height) * DrawingConstant.fontScale)
    }
    
    private struct DrawingConstant {
        static let cornerRadius: CGFloat = 10.0
        static let lineWidth: CGFloat = 3
        static let fontScale: CGFloat = 0.75
    }
}




struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        let game = EmojiMemoryGame()

        EmojiMemoryGameView(game: game)
            .preferredColorScheme(.dark)
.previewInterfaceOrientation(.portraitUpsideDown)

        EmojiMemoryGameView(game: game)
            .preferredColorScheme(.light)
    }
}
