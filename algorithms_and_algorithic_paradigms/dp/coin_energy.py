# pattern: #bottom_up, #state_generation

def get_max_coins(coins, energy, ie):
  # ie is initial energy
  n = len(coins)
  if ie >= n-1:
    return sum(coins)
  dp = [{} for i in range(0, n)]
  dp[0][ie] = coins[0]
  new_energy_state = min(ie + energy[0], n-1)
  dp[0][new_energy_state] = max(0, dp[0].get(new_energy_state, 0))
  g_max = coins[0]
  for i in range(1, n):
    m = 0
    for e in dp[i-1].keys():
      if e-1 >= 0:
        new_energy_state = min(e + energy[i] - 1, n-i-1)
        a = dp[i][new_energy_state] = max(
            dp[i-1][e], dp[i].get(new_energy_state, 0))
        b = 0
        b = dp[i][e-1] = max(dp[i-1][e] + coins[i], dp[i].get(e-1, 0))
        m = max(m, a, b)
    g_max = max(g_max, m)
  # print(dp)
  return g_max


def algo2(coins, energy, ie):
  n = len(energy)
  dp = [[0]*(n+1) for i in range(0, n+1)]
  for i in range(n-1, -1, -1):
      for e in range(0, n+1):
          if (i == n - 1):
              dp[i][e] = coins[i]
          else:
              dp[i][e] = dp[i + 1][min(e + energy[i] - 1, n)]
              if(e - 1 >= 0):
                  dp[i][e] = max(dp[i][e], coins[i] + dp[i + 1][e - 1])
              if (e == 0):
                  dp[i][e] = max(dp[i][e], coins[i])
  return dp[0][min(n, ie)]


tc = int(input())
while tc:
  coins = list(map(int, input().split()))
  energy = list(map(int, input().split()))
  ie = int(input())
  print(get_max_coins(coins, energy, ie))
  print(algo2(coins, energy, ie))
  tc -= 1
