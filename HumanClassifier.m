%% human classifier experiment 
% author : Vanessa Page
% January 2019

clear all;
clc; clear; 
close all;



a = [randperm(10,10) ; randperm(10,10) ; randperm(10,10) ; randperm(10,10) ; randperm(10,10) ; randperm(10,10) ; randperm(10,10); randperm(10,10); randperm(10,10); randperm(10,10)] ; 

if a(:,:) == 1 
    a(:,:) = 'pet'
end


C = cell(size(a));
C(a==1)={'pet'};
C(a==2)={'push'};
C(a==3)={'press'};
C(a==4)={'slap'};
C(a==5)={'poke'};
C(a==6)={'tickle'};
C(a==7)={'rub'};
C(a==8)={'pat'};
C(a==9)={'hit'};
C(a==10)={'scratch'};

C

number_of_participants = 7; 

trial_number = linspace(1,number_of_participants*2,number_of_participants*2);

prob_correct_guessed_all = [10,9,9,10,9,9,9,9,6,6,8,7,8,8];

oddindex = @(prob_correct_guessed_all) prob_correct_guessed_all(1:2:end);
evenindex = @(prob_correct_guessed_all) prob_correct_guessed_all(2:2:end);
prob_correct_guessed_VP = oddindex(prob_correct_guessed_all);
prob_correct_guessed_others = evenindex(prob_correct_guessed_all);

mean_probability_all = mean(prob_correct_guessed_all);
mean_probability_VP = mean(prob_correct_guessed_VP);
mean_probability_others = mean(prob_correct_guessed_others);

prob_correct_guessed_newParticipants = [9,9,6,6,8,7,8,8];
prob_correct_guessed_repeatParticipants = [10,9,9,10,9,9];

mean_probability_newParticipants = mean(prob_correct_guessed_newParticipants);
mean_probability_repeatParticipants = mean(prob_correct_guessed_repeatParticipants);



