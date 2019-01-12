%% Nise Project
% Feature extraction from online found social touch database
clc;
clear;
filename = "CoST.csv"; 
m = csvread(filename,1,0); 

% Data structure
% 	File: CoST.csv Data format: subject, variant, gesture, frame counter,
% 	pressure values of channel (ch) 1-64
% 
% 	Attributes:
% #1. subject - subject number (domain: 1-31)
% 
% #2. variant - variant label (domain: 1-3):
% 			1 = gentle, 2 = normal, 3 = rough
% #3. gesture - gesture label (domain: 1-14):
% 			1 = grab, 2 = hit, 3 = massage, 4 = pat, 5 = pinch, 6 = poke, 7
% 			= press, 8 = rub, 9 = scratch, 10 = slap, 11 = squeeze, 12 =
% 			stroke, 13 = tap, 14 = tickle
% #4. frame counter - counter of frames within a capture (domain: 1-n,
% where n is the total number of frames
% 		within a gesture capture)
% 
% #5-68. pressure values of channel (ch) 1-64 - pressure sensor data
% (domain: 0-1023)

% Data format: subject, variant, gesture, frame counter, pressure values of
% channel (ch) 1-64 (68 columns); actual data starts from column 5

% the # of rows reflects the stacked time sequences for each sensor,
% subject, gesture and trial


% Note. on column 4, each time we have a 1, a new temporal sequence
% starts, % so create an array that contains the row indexes where each new
% time % sequence starts (these starting indexes will be the same for all %
% columns/channels)

start_time_idx = find(m(:,4) == 1); 
gesture_labels = [ "grab", "hit", "massage", "pat", "pinch","poke","press"...
    , "rub", "scratch", "slap", "squeeze", "stroke", "tap", "tickle"];

%% Data visualization
% plot the first 10 channels of subject 1 
figure
title("signals from subject 1, gesture 1,variant 1");
for i=1:10
    subplot(10,1,i)
    plot(m(1:start_time_idx(2)-1,i+5))
    xlabel("time"); ylabel(["ch",num2str(i)])
end

% plot the first 6 trials of gesture 1, variant 1, subject 1, channel 1
figure
for i=1:6
    subplot(6,1,i)
    plot(m(start_time_idx(i):start_time_idx(i+1),5)) % first 6 temporal sequences of channel 1 (on col 5)
    xlabel("time"); ylabel(["ch1, trial ",num2str(i)])
end

% Next, plot the 3D pattern of the artificial skin as an animation

% Create the channels mesh grid (8x8 channels):
[x,y] = meshgrid((1:8),(1:8)); 

% Bring the channels in the correct squared array as described in the readme file
% a = [1:64];
% b = reshape(a,[8,8]);
% b = b';
% b = b(end:-1:1,:); % this is the channel mapping we want to have 

% Do the same with the actual data from all the channels for different gestures

% Initialize array of stacked signals from a single channel:
stacked_sigs = zeros (8,8,start_time_idx(2)); 
% 3rd dimension corresponds to the time points

for i=1:start_time_idx(2) % i = time idx
    sig = m(i,5:end); % first extract the data for gesture 1 from all the channels for the current time point
    % next, reshape signal values in the sqaured array and respect the
    % channel mapping order
    sig = reshape(sig,[8,8]);
    sig = sig';
    sig = sig(end:-1:1,:);
    stacked_sigs(:,:,i) = sig;
end

fig1 = figure
s = surf(x,y,stacked_sigs(:,:,1));
xlabel('x channel coordinate','rotation', 20);
ylabel('y channel coordinate','rotation', -30);
zlabel('Sensor value');
xlim([1 8]); ylim([1 8]);
colorbar;
title([gesture_labels(1), 'gesture']); % subject 1 

% Create animation and save it as gif file
for i=1:start_time_idx(2)
    s.ZData = stacked_sigs(:,:,i);
    pause(0.05)
    frame = getframe(fig1);
    im{i} = frame2im(frame);
end

% Check if the saved 3D plot looks right
figure;
imshow(im{1});

% Create animation
filename = 'testAnimated.gif'; % Specify the output file name
for idx = 1:65
    [A,map] = rgb2ind(im{idx},256);
    if idx == 1
        imwrite(A,map,filename,'gif','DelayTime',0.08);
    else
        imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.08);
    end
end

clear stacked_sigs

% Plot the pattern of the first instance of ALL the gestures from subject 5
%  
for touch_idx = 1:14 % the gesture index
    clear stacked_sigs
    % First retrieve all the indexes of the columns and rows for subject 5
    % and current gesture (given by touch_idx)
    [row,col] = find(m(:,1)==5 & m(:,3)== touch_idx);
    
    % Find the time index when the first instance of that gesture for
    % subject 5 begins
    touch_time_idx = find(start_time_idx == row(1));
    
    % initialize array of stacked signals (again 3rd dim represents the
    % time)
    stacked_sigs = zeros (8,8,(start_time_idx(touch_time_idx+1)-start_time_idx(touch_time_idx))); 
    j = 1; % another time idx that starts from one (for the stacked_sigs array)
    for i = start_time_idx(touch_time_idx):start_time_idx(touch_time_idx+1)-1 % i = time point idx
        sig = m(i,5:end); % extract the data from all the channels in the current time point
        sig = reshape(sig,[8,8]);
        sig = sig';
        sig = sig(end:-1:1,:);
        stacked_sigs(:,:,j) = sig;
        j = j+1;
    end

    % Open current figure
    fig = figure(touch_idx)
    s = surf(x,y,stacked_sigs(:,:,1));
    xlabel('x channel coordinate','rotation', 20);
    ylabel('y channel coordinate','rotation', -30);
    zlabel('Sensor value');
    xlim([1 8]); ylim([1 8]);
    colorbar;

    % Create animation and save it as gif file
    for n=1:size(stacked_sigs,3)
        s.ZData = stacked_sigs(:,:,n);
        title([gesture_labels(touch_idx), 'gesture', 'time frame ',num2str(n)]);
        pause(0.005)
        frame = getframe(fig); % save curr animation frame
        im{n} = frame2im(frame);
    end

    filename = strcat('subject5_',gesture_labels(touch_idx),'.gif'); % the gif file name
    for idx = 1:size(stacked_sigs,3)
        [A,map] = rgb2ind(im{idx},256);
        if idx == 1
            imwrite(A,map,filename,'gif','DelayTime',0.03);
        else
            imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.03);
        end
    end
close all; clear fig s im A j
end

%% FEATURE EXTRACTION
clearvars -except m