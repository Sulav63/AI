my $msg = 'Ronaldo cannot win worldcup!';

my $adj = substr($msg, 8, 6);      # Extract a portion of string ('cannot')

print $adj, "\n";                  # Output: 'cannot'

print substr($msg, 8), "\n";       # Output: 'cannot win worldcup!'

substr($msg, 8, 6) = 'will never'; # Modify a portion of the string to 'Ronaldo will never win worldcup!'

print $msg, "\n";                  # Output: 'Ronaldo will never win worldcup!'
