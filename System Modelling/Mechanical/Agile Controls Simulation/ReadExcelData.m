%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Main File   : ReadExcelData.m
% Source Files: ParameterConfig.xlsx
% Dependancies: xlsRead
% Description : Reads excel data (Parameter config file) for the different
% parameters of the robot
% Input       : None
% Output      : data - represents all the robot parameters
% Author      : Logan Beaver
% Date        : 03/01/2015
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function data = ReadExcelData()
%% Input handling

% If no sheet is specified, read first sheet
    sheet = 1;


% read 12 data points
    startRow = 1;
    endRow = 12;

%% Import the data
data = xlsread('ParameterConfig.xlsx', sheet, sprintf('B%d:B%d',startRow(1),endRow(1)));
for block=2:length(startRow)
    tmpDataBlock = xlsread('ParameterConfig.xlsx', sheet, sprintf('B%d:B%d',startRow(block),endRow(block)));
    data = [data;tmpDataBlock]; %#ok<AGROW>
end

