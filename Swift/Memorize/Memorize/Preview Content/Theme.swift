//
//  Theme.swift
//  Memorize
//
//  Created by Vincent Diribarne (i202597) on 17/03/2022.
//

import Foundation
import SwiftUI

class ThemeManager {
    static var ThemeVehicule = Theme(listeEmoji: ["π", "π", "π", "π", "π", "π΅", "π²", "π", "π", "π", "π", "π", "π", "π", "π»", "π"], color: Color.red)
    static var ThemeFruit = Theme(listeEmoji:["π", "π", "π", "π", "π", "π", "π", "π«", "π", "π", "π", "π₯­", "π", "π₯₯", "π₯", "π", "π"], color: Color.blue)
    static var ThemeFood = Theme(listeEmoji: ["π₯", "π₯―", "π", "π₯", "π₯¨", "π§", "π₯", "π³", "π§", "π­", "π₯", "π§", "π₯", "π₯©", "π", "π", "π", "π", "π"], color: Color.cyan)
    static var ThemeSport = Theme(listeEmoji: ["β½οΈ", "π", "π", "βΎοΈ", "π₯", "πΎ", "π", "π", "π₯", "π±", "π", "πͺ", "πΈ", "π", "π", "π₯", "π", "πͺ"], color: Color.green)
    
    static func ChooseTheme() -> Theme {
        let Array = [ThemeVehicule, ThemeFruit, ThemeFood, ThemeSport]
        return Array.randomElement()!
    }
}

struct Theme {
    var listeEmoji : Array<String>
    var color : Color
}
