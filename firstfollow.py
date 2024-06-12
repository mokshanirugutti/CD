def compute_first(grammar, symbol, first, visited):
    if symbol in first:
        return first[symbol]
    if symbol in visited:
        return set()

    visited.add(symbol)
    result = set()
    for production in grammar[symbol]:
        next_symbol = production[0]
        if next_symbol not in grammar:
            result.add(next_symbol)
        else:
            result.update(compute_first(grammar, next_symbol, first, visited))
    visited.remove(symbol)
    first[symbol] = result
    return result

def compute_follow(grammar, symbol, follow, first, visited, start_symbol):
    if symbol in follow:
        return follow[symbol]
    if symbol in visited:
        return set()

    visited.add(symbol)
    result = set()
    if symbol == start_symbol:
        result.add('$')

    for nt, productions in grammar.items():
        for production in productions:
            if symbol in production:
                idx = production.index(symbol)
                if idx < len(production) - 1:
                    next_symbol = production[idx + 1]
                    if next_symbol not in grammar:
                        result.add(next_symbol)
                    else:
                        result.update(compute_first(grammar, next_symbol, first, visited))
                else:
                    if nt != symbol:
                        result.update(compute_follow(grammar, nt, follow, first, visited, start_symbol))

    follow[symbol] = result
    visited.remove(symbol)
    return result

grammar = {}
first = {}
follow = {}

num_productions = int(input("Enter the number of productions: "))
for _ in range(num_productions):
    nt, prods = input("Enter the production: ").split('-')
    grammar[nt] = prods.split('|')

start_symbol = list(grammar.keys())[0]

while True:
    symbol = input("Enter the symbol whose FIRST and FOLLOW sets are to be found: ")
    print(f"FIRST({symbol}) = {compute_first(grammar, symbol, first, set())}")
    print(f"FOLLOW({symbol}) = {compute_follow(grammar, symbol, follow, first, set(), start_symbol)}")
    if input("Continue (y/n)? ") != 'y':
        break
