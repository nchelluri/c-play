#!/usr/bin/env ruby

unless ARGV.length == 1
  puts "#{$0} filename"
  exit 1
end

File.open(ARGV[0], 'r') do |f|
  i = 0
  while line = f.gets
    unless line =~ /^\[#{i}\]: #{i+1}$/
      puts "Bad line #{i+1}: #{line}"
      exit 2
    end
    i = i+1
  end
end

puts "All good lines"
