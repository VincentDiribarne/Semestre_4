//
//  Theme.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 17/03/2022.
//

import Foundation
import SwiftUI

class ThemeManager {
    static var ThemeVehicule = Theme(listeEmoji: ["🚗", "🚑", "🚚", "🚓", "🚛", "🛵", "🚲", "🚕", "🚙", "🚌", "🚎", "🏎", "🚒", "🚐", "🛻", "🚜"], color: Color.red)
    static var ThemeFruit = Theme(listeEmoji:["🍏", "🍊", "🍋", "🍌", "🍉", "🍇", "🍓", "🫐", "🍈", "🍒", "🍑", "🥭", "🍍", "🥥", "🥝", "🍅", "🍆"], color: Color.blue)
    static var ThemeFood = Theme(listeEmoji: ["🥐", "🥯", "🍞", "🥖", "🥨", "🧀", "🥚", "🍳", "🧈", "🌭", "🥞", "🧇", "🥓", "🥩", "🍗", "🍖", "🍔", "🍟", "🍕"], color: Color.cyan)
    static var ThemeSport = Theme(listeEmoji: ["⚽️", "🏀", "🏈", "⚾️", "🥎", "🎾", "🏐", "🏉", "🥏", "🎱", "🏓", "🪀", "🏸", "🏒", "🏑", "🥍", "🏏", "🪃"], color: Color.green)
    
    static func ChooseTheme() -> Theme {
        let Array = [ThemeVehicule, ThemeFruit, ThemeFood, ThemeSport]
        return Array.randomElement()!
    }
}

struct Theme {
    var listeEmoji : Array<String>
    var color : Color
}
