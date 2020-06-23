#!/bin/ruby
# https://www.hackerrank.com/challenges/mini-max-sum/problem
require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
min = arr[0] 
max = arr[0]
sum = arr[0]
i=1
while(i<arr.length)
max = arr[i] if arr[i]>max
min = arr[i] if arr[i]<min
sum+=arr[i]
i+=1
end
puts "#{sum-max} #{sum-min}"
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
