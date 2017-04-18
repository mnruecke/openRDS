# Run openRDS and visualze results using matlab/octave

# 1. compile and run
if isunix
	unix('make && ./openRDS');
else
	disp(['Error: need to adjust "', mfilename('fullpath'), '.m" for windows'])
    break;
end

# 2. load data
data = load('results.dat');

# 3. display data
plot3( data(1,:), data(2,:), data(3,:),'+','LineWidth',3); hold on;
plot3( data(1,:), data(2,:), data(3,:)); hold off;

