import random

logo = """
.------.            _     _            _    _            _    
|A_  _ |.          | |   | |          | |  (_)          | |   
|( \/ ).-----.     | |__ | | __ _  ___| | ___  __ _  ___| | __
| \  /|K /\  |     | '_ \| |/ _` |/ __| |/ / |/ _` |/ __| |/ /
|  \/ | /  \ |     | |_) | | (_| | (__|   <| | (_| | (__|   < 
`-----| \  / |     |_.__/|_|\__,_|\___|_|\_\ |\__,_|\___|_|\_\\
      |  \/ K|                            _/ |                
      `------'                           |__/           
"""

def deal_card():
        cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
        card = random.choice(cards)
        return card

def calculate_score(cards):
        if sum(cards) == 21 and len(cards) == 2:
            return 0
        if 11 in cards and sum(cards) > 21:
            cards.remove(11)
            cards.append(1)
        return sum(cards)

def compare(your_score, enem_score):
        if your_score == enem_score:
            return "Unentschieden"
        elif enem_score == 0:
            return "Verloren, der Gegner hat Blackjack"
        elif your_score == 0:
            return "Gewonnen, du hast Blackjack"
        elif your_score > 21:
            return "21 überschritten. Du hast verloren."
        elif enem_score > 21:
            return "Gegner hat 21 überschritten. Du hast gewonnen."
        elif your_score > enem_score:
            return "Du gewinnst!"
        elif your_score < enem_score:
            return "Du verlierst!"

def playgame():
    your_cards = []
    enem_cards = []
    is_game_over = False
    print(logo)
    for cards in range(2):
        your_cards.append(deal_card())
        enem_cards.append(deal_card())
    while not is_game_over:
        your_score = calculate_score(your_cards)
        enem_score = calculate_score(enem_cards)
        print(f"Deine Karten: {your_cards}, aktueller Punktestand: {your_score}\n")
        print(f"Erste Karte vom Gegner: {enem_cards[0]}")
        if your_score == 0 or enem_score == 0 or your_score > 21:
            is_game_over = True
        else:
            choice = input("Tippe 'j', um noch eine weitere Karte zu ziehen und 'n', wenn nicht:  ")
            if choice == "j":
                your_cards.append(deal_card())
            else:
                is_game_over = True
    while enem_score != 0 and enem_score <17:
        enem_cards.append(deal_card())
        enem_score = calculate_score(enem_cards)
    print(f"Deine Karten: {your_cards}, finaler Punktestand: {your_score}\nKarten vom Gegner: {enem_cards}, Punktestand: {enem_score}")
    print(compare(your_score, enem_score))

while input("Tippe 'j', wenn du eine Runde Blackjack starten möchtest. ") == "j":
    playgame()